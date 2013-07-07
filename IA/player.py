#!/usr/bin/python

import time
import cmath
import math
import Queue
import base64
import collections

from action import *
from elevation import *
from case import *
from inventaire import *

defaultdict = collections.defaultdict

class player:
    def _createMap(self):
        i = 0;
        while (i != self._lenMapX * self._lenMapY):
            self._map.append(case())
            i = i + 1

    def __init__(self, socket, team):
        self._posX = 0
        self._posY = 0
        self._lenMapX = 0
        self._lenMapY = 0
        self._socket = socket
        self._orientation = 0
        self._map = []
        self._team = team
        self._inventaire = inventaire()
        self._action = action()
        self._queue = Queue.Queue()
        self._elevation = elevation()
        self._lvl = 1
        self._processing = defaultdict(int)

    def connect(self):
        self._socket.send(self._team + "\n")
        time.sleep(0.05)
        answer = self._socket.recv(1000)
        answer = answer.split('\n')
        self._numClient = int(answer[1])
        answer = answer[2].split(' ')
        self._lenMapX = int(answer[0])
        self._lenMapY = int(answer[1])
        self._createMap()
        self.inventaire()
        self.fork()

    def broadcast(self, msg)
    	self._socket.send(msg)

    def myAbsolute(self, nb, opt):
        if (nb >= 0):
            return (nb)
        else:
            return (nb + opt)

    def turnLeft(self):
        self._socket.send("gauche\n")
        self._queue.put("gauche\n")
        time.sleep(0.05)
        if (self._orientation == 0):
            self._orientation = 3
        else :
            self._orientation = self._orientation - 1

    def turnRight(self):
        self._socket.send("droite\n")
        self._queue.put("droite\n")
        time.sleep(0.05)
        self._orientation = (self._orientation + 1) % 4

    def avance(self):
        print "avance"
        self._socket.send("avance\n")
        self._queue.put("avance\n")
        time.sleep(0.05)
        if (self._orientation == 0):
            self._posY = self.myAbsolute(self._posY - 1, self._lenMapY)
        elif (self._orientation == 1):
            self._posX = (self._posX + 1) % self._lenMapX
        elif (self._orientation == 2):
            self._posY = (self._posY + 1) % self._lenMapY
        else:
            self._posX = self.myAbsolute(self._posX - 1, self._lenMapX)

    def goUp(self):
        while self._orientation != 0:
            if (self._orientation == 1):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def goDown(self):
        while self._orientation != 2:
            if (self._orientation == 3):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def goLeft(self):
        while self._orientation != 3:
            if (self._orientation == 0):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def goRight(self):
        while self._orientation != 1:
            if (self._orientation == 2):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def voir(self):
        self._socket.send("voir\n")
        time.sleep(0.05)

    def incantation(self):
        self._socket.send("incantation\n")
        self._queue.put("incantation\n")

    def _treatCase(self, tab, i):
        tmp = 0
        x = 0
        y = 0
        sommes = 1 + (2 * y)
        while (tmp <= i):
            if (tmp >= sommes):
                y = y + 1
                sommes = sommes + (1 + (2 * y))
            tmp = tmp + 1
        x = i - (sommes - (1 + (2 * y)))
        x = x - ((1 + (2 * y)) / 2)
        if (self._orientation == 0):
            tmpx = (self.myAbsolute(self._posX + x, self._lenMapX)) % self._lenMapX
            tmpy = self.myAbsolute(self._posY - y, self._lenMapY)
        elif (self._orientation == 1):
            tmpy = self.myAbsolute(self._posY + x, self._lenMapY) % self._lenMapY
            tmpx = (self._posX + y) % self._lenMapX
        elif (self._orientation == 2):
            tmpx = (self.myAbsolute(self._posX - x, self._lenMapX)) % self._lenMapX
            tmpy = (self._posY + y) % self._lenMapY
        elif (self._orientation == 3):
            tmpy = (self.myAbsolute(self._posY - x, self._lenMapY)) % self._lenMapY
            tmpx = (self.myAbsolute(self._posX - y, self._lenMapX)) % self._lenMapX
        i = self._lenMapX * tmpy + tmpx
        self._map[i].reset();
        self._map[i].set(tab)

    def changeMapVoir(self, answer):
        tab = answer.split(',')
        i = 0
        while (i < tab.__len__()):
            tab[i] = tab[i].split(' ')
            self._treatCase(tab[i], i);
            i = i + 1

    def affMap(self):
        i = 0
        while i < self._map.__len__():
            self._map[i].aff()
            i = i + 1
            if (i % self._lenMapX == 0):
                print ""

    def fork(self):
        self._socket.send("fork\n")

    def reduceProbabilities(self):
        i = 0
        while i < self._map.__len__():
            self._map[i].reduceProbabilities()
            i = i + 1

    def inventaire(self):
        self._socket.send("inventaire\n")
        time.sleep(0.05)

    def modifieInventaire(self, string):
        string = string.split('{')
        string = string[1].split('}')
        tab = string[0].split(',')
        i = 0
        while (i < tab.__len__()):
            tab[i] = tab[i].split(' ')
            self._inventaire.modifie(tab[i][0], int(tab[i][1]))
            i = i + 1

    def prendreObject(self, Object):
        toSend = "prend " + Object + "\n"
        self._socket.send(toSend)
        self._queue.put(toSend)
        time.sleep(0.05)

    def poserObject(self, Object):
        toSend = "pose " + Object + "\n"
        self._socket.send(toSend)
        self._queue.put(toSend)
        time.sleep(0.05)

    def findFood(self, emergency):
        j = 0
        x = 0
        y = 0
        nb = 100000
        while j < self._lenMapY:
            i = 0
            while i < self._lenMapX:
                tmp = math.fabs(self._posX - i) + math.fabs(self._posY - j)
                tmp2 = self._lenMapX * j + i
                if tmp < nb and self._map[tmp2]._nourriture > 0:
                    x = i
                    y = j
                    nb = tmp
                i = i + 1
            j = j + 1
        if nb != 100000:
            return [x, y]
        return [-1, -1]

    def checkFindStone(self, i, stone):
        if (stone == "linemate" and self._map[i]._linemate > 0):
            return 1
        elif (stone == "deraumere" and self._map[i]._deraumere > 0):
            return 1
        elif (stone == "sibur" and self._map[i]._sibur > 0):
            return 1
        elif (stone == "mendiane" and self._map[i]._mendiane > 0):
            return 1
        elif (stone == "phiras" and self._map[i]._phiras > 0):
            return 1
        elif (stone == "thystame" and self._map[i]._thystame > 0):
            return 1
        elif (stone == "nourriture" and self._map[i]._nourriture > 0):
            return 1
        return 0

    def findStone(self, stone):
        j = 0
        x = 0
        y = 0
        nb = 100000
        while j < self._lenMapY:
            i = 0
            while i < self._lenMapX:
                tmp = math.fabs(self._posX - i) + math.fabs(self._posY - j)
                tmp2 = self._lenMapX * j + i
                if tmp < nb and self.checkFindStone(tmp2, stone) == 1:
                    x = i
                    y = j
                    nb = tmp
                i = i + 1
            j = j + 1
        if nb != 100000:
            return [x, y]
        return [-1, -1]

    def CompareTwoPos(self, Pos1, Pos2):
        tmp = math.fabs(self._posX - Pos1[0]) + math.fabs(self._posY - Pos1[1])
        tmp2 = math.fabs(self._posX - Pos2[0]) + math.fabs(self._posY - Pos2[1])
        if tmp < tmp2:
            return True
        return False

    def decideCaseToGo(self):
        tab = self.findFood(3)
        if tab[0] != -1 and tab[1] != -1:
            if (self._inventaire._nourriture < 5):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 3)
            elif (self._inventaire._nourriture < 100):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 2)
            elif (self._inventaire._nourriture < 150):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 1)

    def deplacementAbsolut(self, x, y):
        if (self._posX != x):
            x1 = self.myAbsolute(self._posX - x, self._lenMapX)
            x2 = self.myAbsolute(x - self._posX, self._lenMapX)
            if (x1 < x2):
                self.goLeft()
            else:
                self.goRight()
        else:
            y1 = self.myAbsolute(self._posY - y, self._lenMapY)
            y2 = self.myAbsolute(y - self._posY, self._lenMapY)
            if (y1 < y2):
                self.goUp()
            else:
                self.goDown()

    def createArea(self, x1, x2, y1, y2):
        if x1 < x2:
            left = 1
        else:
            left = 0
        if y1 < y2:
            up = 1
        else:
            up = 0
        y = self._posY
        to_return = []
        while (y != self._action._y):
            x = self._posX
            while (x != self._action._x):
                to_return.append([x, y])
                if left == 1:
                    x = self.myAbsolute(x - 1, self._lenMapX)
                else :
                    x = (x + 1) % self._lenMapX
            if up == 1:
                y = self.myAbsolute(y - 1, self._lenMapY)
            else:
                y = (y + 1) % self._lenMapX
        return to_return

    def checkIfTabBelowToTab(self, area, tab):
        i = 0
        while i < area.__len__():
            if (area[i][0] == tab[0] and area[i][1] == tab[1]):
                return 1
            i = i + 1
        return 0

    def choseStoneToFind(self, area):
        myNeed = self._elevation.getNeed(self._lvl)
        i = 0
        res = [10000, 10000]
        while i < self._action._secondAction.__len__():
            tab = self.findStone(self._action._secondAction[i])
            if (self.checkIfTabBelowToTab(area, tab) == 1 and self.CompareTwoPos(tab, res) == True):
                res[0] = tab[0]
                res[1] = tab[1]
            i = i + 1
        return res

    def moveToAction(self):
        if self._action._emergency == 3:
            self.deplacementAbsolut(self._action._x , self._action._y)
        else:
            x1 = self.myAbsolute(self._posX - self._action._x, self._lenMapX)
            x2 = self.myAbsolute(self._action._x - self._posX, self._lenMapX)
            y1 = self.myAbsolute(self._posY - self._action._y, self._lenMapY)
            y2 = self.myAbsolute(self._action._y - self._posY, self._lenMapY)
            area = self.createArea(x1, x2, y1, y2)
            tab = self.choseStoneToFind(area)
            if (tab[0] != 10000):
                self.deplacementAbsolut(tab[0], tab[1])
            else:
                self.deplacementAbsolut(self._action._x, self._action._y)

    def takeObjectif(self):
        if self._action._firstAction >= self._action._PossibleAction._nourriture and self._action._firstAction <= self._action._PossibleAction._thystame:
            self.prendreObject(self._action._tabPossibleAction[self._action._firstAction])
            tmp = self._lenMapX * self._posY + self._posX
            if (self._map[tmp]._nourriture > 0):
                self._map[tmp]._nourriture -= 1
        self._action._define = -1
    def takeObject(self):
        i = self._lenMapX * self._posY + self._posX
        j = 0
        while j < self._action._secondAction.__len__():
            if (self._action._secondAction[j] == self._action._PossibleAction._linemate and self._map[i]._linemate > 0
):
                self.prendreObject("linemate")
                self._map[i]._linemate -= 1
            elif (self._action._secondAction[j] == self._action._PossibleAction._deraumere and self._map[i]._deraumere > 0):
                self.prendreObject("deraumere")
                self._map[i]._deraumere -= 1
            elif (self._action._secondAction[j] == self._action._PossibleAction._sibur and self._map[i]._sibur > 0):
                self.prendreObject("sibur")
                self._map[i]._sibur -= 1
            elif (self._action._secondAction[j] == self._action._PossibleAction._mendiane and self._map[i]._mendiane > 0):
                self.prendreObject("mendiane")
                self._map[i]._mendiane -= 1
            elif (self._action._secondAction[j] == self._action._PossibleAction._phiras and self._map[i]._phiras > 0):
                self.prendreObject("phiras")
                self._map[i]._phiras -= 1
            elif (self._action._secondAction[j] == self._action._PossibleAction._thystame and self._map[i]._thystame > 0):
                self.prendreObject("thystame")
                self._map[i]._thystame -= 1
            elif (self._action._secondAction[j] == self._action._PossibleAction._nourriture and self._map[i]._nourriture > 0):
                self.prendreObject("nourriture")
                self._map[i]._nourriture -= 1
            j = j + 1

    def goToUnknow(self):
        j = 0
        x = 0
        y = 0
        nb = 100000
        while j < self._lenMapY - 1:
            i = 0
            while i < self._lenMapX - 1:
                tmp = math.fabs(self._posX - i) + math.fabs(self._posY - j)
                tmp2 = self._lenMapX * j + i
                if tmp < nb and self._map[tmp2]._probabilities <= 0:
                    x = i
                    y = j
                    nb = tmp
                i = i + 1
            j = j + 1
        if nb != 100000:
            self.deplacementAbsolut(x, y)
        else:
            self.avance()
        self.voir()

    def decideSecondAction(self):
        myNeed = self._elevation.getNeed(self._lvl)
        if (self._inventaire._linemate < myNeed._linemate):
            self._action.addSecondAction(self._action._PossibleAction._linemate)
        else:
            self._action.delSeconAction(self._action._PossibleAction._linemate)

        if (self._inventaire._deraumere < myNeed._deraumere):
            self._action.addSecondAction(self._action._PossibleAction._deraumere)
        else:
            self._action.delSeconAction(self._action._PossibleAction._deraumere)

        if (self._inventaire._sibur < myNeed._sibur):
            self._action.addSecondAction(self._action._PossibleAction._sibur)
        else:
            self._action.delSeconAction(self._action._PossibleAction._sibur)

        if (self._inventaire._mendiane < myNeed._mendiane):
            self._action.addSecondAction(self._action._PossibleAction._mendiane)
        else:
            self._action.delSeconAction(self._action._PossibleAction._mendiane)

        if (self._inventaire._phiras < myNeed._phiras):
            self._action.addSecondAction(self._action._PossibleAction._phiras)
        else:
            self._action.delSeconAction(self._action._PossibleAction._phiras)

        if (self._inventaire._thystame < myNeed._thystame):
            self._action.addSecondAction(self._action._PossibleAction._thystame)
        else:
            self._action.delSeconAction(self._action._PossibleAction._thystame)

    def putObjectIncantation(self):
        myNeed = self._elevation.getNeed(self._lvl)
        i = self._lenMapX * self._posY + self._posX
        if (self._map[i]._linemate < myNeed._linemate):
            self.poserObject("linemate")
        if (self._map[i]._deraumere < myNeed._deraumere):
            self.poserObject("deraumere")
        if (self._map[i]._sibur < myNeed._sibur):
            self.poserObject("sibur")
        if (self._map[i]._mendiane < myNeed._mendiane):
            self.poserObject("mendiane")
        if (self._map[i]._phiras < myNeed._phiras):
            self.poserObject("phiras")
        if (self._map[i]._thystame < myNeed._thystame):
            self.poserObject("thystame")

<<<<<<< HEAD
# a modifier : pu de check d'inventaire, incantation en 3 etapes : on annonce l'incantation si y'a rien a notre niveau dans la queue d'incantation, on stock l'id de notre incantation dans notre queue, puis on broadcast des demandes de "besoin"
    def incantIfPossible(self):
        myNeed = self._elevation.getNeed(self._lvl)
        i = self._lenMapX * self._posY + self._posX
        self.voir()
        time.sleep(0.05)
        if (self._map[i]._players == myNeed._joueur)
        	if (self._map[i]._linemate >= myNeed._linemate and self._map[i]._deraumere >= myNeed._deraumere and self._map[i]._sibur >= myNeed._sibur and self._map[i]._mendiane >= myNeed._mendiane and self._map[i]._phiras >= myNeed._phiras and self._map[i]._thystame >= myNeed._thystame):
                self.incantation()
                self._lvl = 2 #provisoir
                return True
            else:
               	self.putObjectIncantation()
                return True
        else:
        	# broadcast besoin
        	print ""
=======
    def takeObjectIncantation(self):
        myNeed = self._elevation.getNeed(self._lvl)
        i = self._lenMapX * self._posY + self._posX
        if (self._map[i]._linemate > myNeed._linemate):
            self.prendreObject("linemate")
        if (self._map[i]._deraumere > myNeed._deraumere):
            self.prendreObject("deraumere")
        if (self._map[i]._sibur > myNeed._sibur):
            self.prendreObject("sibur")
        if (self._map[i]._mendiane > myNeed._mendiane):
            self.prendreObject("mendiane")
        if (self._map[i]._phiras > myNeed._phiras):
            self.prendreObject("phiras")
        if (self._map[i]._thystame > myNeed._thystame):
            self.prendreObject("thystame")

    def incantIfPossible(self):
        myNeed = self._elevation.getNeed(self._lvl)
        i = self._lenMapX * self._posY + self._posX
        if (self._inventaire._linemate + self._map[i]._linemate >= myNeed._linemate and self._inventaire._deraumere + self._map[i]._deraumere >= myNeed._deraumere and self._inventaire._sibur + self._map[i]._sibur >= myNeed._sibur and self._inventaire._mendiane + self._map[i]._mendiane >= myNeed._mendiane and self._inventaire._phiras + self._map[i]._phiras >= myNeed._phiras and self._inventaire._thystame + self._map[i]._thystame >= myNeed._thystame and self._lvl == 1):
            if (self._map[i]._linemate == myNeed._linemate and self._map[i]._deraumere == myNeed._deraumere and self._map[i]._sibur == myNeed._sibur and self._map[i]._mendiane == myNeed._mendiane and self._map[i]._phiras == myNeed._phiras and self._map[i]._thystame == myNeed._thystame):
                self.incantation()
                print "elevation"
                return False
            elif (self._map[i]._linemate < myNeed._linemate or self._map[i]._deraumere < myNeed._deraumere or self._map[i]._sibur < myNeed._sibur or self._map[i]._mendiane < myNeed._mendiane or self._map[i]._phiras < myNeed._phiras or self._map[i]._thystame < myNeed._thystame):
                #if Il manque des objects :
                print "I can't move."
                self.putObjectIncantation()
                #elif Il manque des personnes brodcast Incantation
                self.voir()
                return True
            elif (self._map[i]._linemate > myNeed._linemate or self._map[i]._deraumere > myNeed._deraumere or self._map[i]._sibur > myNeed._sibur or self._map[i]._mendiane > myNeed._mendiane or self._map[i]._phiras > myNeed._phiras or self._map[i]._thystame > myNeed._thystame):
                print "I can't move."
                self.takeObjectIncantation()
                self.voir()
                return True
>>>>>>> a36ebcd3564011d045ef9bd246579c151c8bcf44
        return False

    def findGoodMove(self):
        elevationPossible = False
#        self._action.affSecondAction()
        if (self._inventaire._nourriture < 5):
            tab = self.findFood(3)
            if (tab[0] != -1 and tab[1] != -1):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 3)
        elif self._action._emergency != 3:
            self.takeObject()
            elevationPossible = self.incantIfPossible()
        self.decideSecondAction()
        if (self._posX == self._action._x and self._posY == self._action._y and self._action._define == 0):
            self.takeObjectif()
        elif ((self._posX != self._action._x or self._posY != self._action._y) and self._action._define == 0 and elevationPossible == False):
            self.moveToAction()
        elif elevationPossible == False:
            self.goToUnknow()
            self.decideCaseToGo()
        self.reduceProbabilities()

    def treatOk(self, trame):
#        print trame
        if trame == "ok" or trame == "ko":
            if self._queue.empty() != True:
                tmp = self._queue.get()
                if tmp.split(' ')[0] == "prend" and trame == "ok":
                    self._inventaire.addOne(tmp.split(' ')[1].split('\n')[0])
                if tmp.split(' ')[0] == "pose" and trame == "ok":
                    self._inventaire.delOne(tmp.split(' ')[1].split('\n')[0])
        # traitement de reception de broadcast trame = "message X,txt"
        elif trame[0:6] == "niveau":
            print "I up"
            self._lvl = self._lvl + 1
            self._queue.get()
        elif trame[0:7] == "message":
        	direction = trame[8:9]
       		msg = base64.b64decode(trame[10:len(trame)+1])
       		print msg
        	if msg[0:2] == "IE":
        		# Incantation ennemie
	        	print ""
	        elif msg [0:2] == "IT":
	        	incantation_id = msg[2:4]
	        	del self._processing[incantation_id]
        	elif msg[0:1] == "I":
        		# declaration d'une Incantation
        		# exemple I012
                incantation_id = msg[1:3]
                incantation_lvl = msg[3:4]
                self._processing[incantation_id] = incantation_lvl
            elif msg[0:1] == "B":
            	# besoin de ressources pour une incantation
            	# exemple B01nJnLnDnSnMnPnT
                incantation_id = msg[1:3]
                incantation_lvl = self._processing[incantation_id]
                nb_p = msg[3:4]
                nb_l = msg[5:6]
                nb_d = msg[7:8]
                nb_s = msg[9:10]
                nb_m = msg[11:12]
                nb_p = msg[13:14]
                nb_t = msg[15:16]
