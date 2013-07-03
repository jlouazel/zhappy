#!/usr/bin/python

import time
import cmath
import math
import Queue
from action import *

class case:
    def __init__(self):
        self._linemate = 0
        self._deraumere = 0
        self._sibur = 0
        self._mendiane = 0
        self._phiras = 0
        self._thystame = 0
        self._nourriture = 0
        self._probabilities = 100

    def reset(self):
        self._linemate = 0
        self._deraumere = 0
        self._sibur = 0
        self._mendiane = 0
        self._phiras = 0
        self._thystame = 0
        self._nourriture = 0
        self._probabilities = 100

    def set(self, tab):
        i = 0
        while (i < tab.__len__()):
            print tab[i]
            if (tab[i] == "linemate" or tab[i] == "linemate}"):
                self._linemate += 1
            if (tab[i] == "deraumere" or tab[i] == "deraumere}"):
                self._deraumere += 1
            if (tab[i] == "sibur" or tab[i] == "sibur}"):
                self._sibur += 1
            if (tab[i] == "mendiane" or tab[i] == "mendiane}"):
                self._mendiane += 1
            if (tab[i] == "phiras" or tab[i] == "phiras}"):
                self._phiras += 1
            if (tab[i] == "thystame" or tab[i] == "thystame}"):
                self._thystame += 1
            if (tab[i] == "nourriture" or tab[i] == "nourriture}"):
                self._nourriture += 1
            i = i + 1

    def aff(self):
        print "{",
        if self._linemate >= 1:
            print "linemate, ",
        if self._deraumere >= 1:
            print "deraumere, ",
        if self._sibur >= 1:
            print "sibur, ",
        if self._mendiane >= 1:
            print "mendiane, ",
        if self._phiras >= 1:
            print "phiras, ",
        if self._thystame >= 1:
            print "thystame, ",
        if self._nourriture >= 1:
            print "nourriture",
        print "}",

    def reduceProbabilities(self):
        if self._probabilities > 0:
            self._probabilities = self._probabilities - 2

class inventaire:
    def __init__(self):
        self._linemate = 0
        self._deraumere = 0
        self._sibur = 0
        self._mendiane = 0
        self._phiras = 0
        self._thystame = 0
        self._nourriture = 0

    def modifie(self, string, nb):
        if (string == "linemate"):
            self._linemate = nb
        if (string == "deraumere"):
            self._deraumere = nb
        if (string == "sibur"):
            self._sibur = nb
        if (string == "mendiane"):
            self._mendiane = nb
        if (string == "phiras"):
            self._phiras = nb
        if (string == "thystame"):
            self._thystame = nb
        if (string == "nourriture"):
            self._nourriture = nb

    def addOne(self, string):
        if (string == "linemate"):
            self._linemate += 1
        if (string == "deraumere"):
            self._deraumere += 1
        if (string == "sibur"):
            self._sibur += 1
        if (string == "mendiane"):
            self._mendiane += 1
        if (string == "phiras"):
            self._phiras += 1
        if (string == "thystame"):
            self._thystame += 1
        if (string == "nourriture"):
            self._nourriture += 1

    def aff(self):
        print "{",
        if self._linemate >= 1:
            print "linemate ", self._linemate, ", ",
        if self._deraumere >= 1:
            print "deraumere ", self._deraumere, ", ",
        if self._sibur >= 1:
            print "sibur ", self._sibur, ", ",
        if self._mendiane >= 1:
            print "mendiane ", self._mendiane, ", ",
        if self._phiras >= 1:
            print "phiras ", self._phiras, ", ",
        if self._thystame >= 1:
            print "thystame ", self._thystame, ", ",
        if self._nourriture >= 1:
            print "nourriture ", self._nourriture,
        print "}",

class player:
    def _createMap(self):
        i = 0;
        while (i != self._lenMapX * self._lenMapY):
            self._map.append(case())
            i = i + 1

    def __init__(self, lenMapX, lenMapY, socket, team):
        self._posX = 0
        self._posY = 0
        self._lenMapX = lenMapX
        self._lenMapY = lenMapY
        self._socket = socket
        self._orientation = 0
        self._map = []
        self._createMap()
        self._team = team
        self._inventaire = inventaire()
        self._action = action()
        self._queue = Queue.Queue()

    def connect(self):
        self._socket.send(self._team + "\n")
        time.sleep(0.05)

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
        print "go Up"
        while self._orientation != 0:
            if (self._orientation == 1):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def goDown(self):
        print "go Down"
        while self._orientation != 2:
            if (self._orientation == 3):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def goLeft(self):
        print "go Left"
        while self._orientation != 3:
            if (self._orientation == 0):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def goRight(self):
        print "go Right"
        while self._orientation != 1:
            if (self._orientation == 2):
                self.turnLeft()
            else:
                self.turnRight()
        self.avance()

    def voir(self):
        self._socket.send("voir\n")
        time.sleep(0.05)

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
        print "prendre ", Object
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
            print "Find food at x = ", x, " y = ", y
            #            self._action.setMove(x, y, self._action._PossibleAction._nourriture, emergency)
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

    def decideCaseToGo(self):
        tab = self.findFood(3)
        if tab[0] != -1 and tab[1] != -1:
            if (self._inventaire._nourriture < 5):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 3)
            elif (self._inventaire._nourriture < 100):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 2)
            elif (self._inventaire._nourriture < 150):
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 1)
        if (self._inventaire._nourriture < 15):
            self._action.addSecondAction(self._action._PossibleAction._linemate)

    def deplacementAbsolut(self, x, y):
        if (self._posX != x):
            x1 = self.myAbsolute(self._posX - x, self._lenMapX)
            x2 = self.myAbsolute(x - self._posX, self._lenMapX)
            if (x1 < x2): # Pourquoi pas obtimiser en regardant l'orientation du personnage.
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
            print "lalal1"
            x = self._posX
            while (x != self._action._x):
                print "lalal2 : x = ", x, " y = ", y, " actionX = ", self._action._define
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

    def checkIfTabBelowToTab(self):
        

    def moveToAction(self):
        #Ici definir le mouvement pour chercher l'objectif numero 2 si il est sur le passage ou s'il faut faire un petit detour
        print "I move to action"
        if self._action._emergency == 3:
            self.deplacementAbsolut(self._action._x , self._action._y)
        else:
            x1 = self.myAbsolute(self._posX - self._action._x, self._lenMapX)
            x2 = self.myAbsolute(self._action._x - self._posX, self._lenMapX)
            y1 = self.myAbsolute(self._posY - self._action._y, self._lenMapY)
            y2 = self.myAbsolute(self._action._y - self._posY, self._lenMapY)
            print "Creat Area :"
            area = self.createArea(x1, x2, y1, y2)
            print "finished to Creat Area :"
            tab = self.findStone("linemate")
            print "finished find stone"
            if (self.checkIfTabBelowToTab(area, tab) == 1):
                self.deplacementAbsolut(tab[0], tab[1])
            else:
                self.deplacementAbsolut(self._action._x, self._action._y)

    def takeObjectif(self):
        if self._action._firstAction == self._action._PossibleAction._nourriture:
            self.prendreObject("nourriture")
            tmp = self._lenMapX * self._posY + self._posX
            if (self._map[tmp]._nourriture > 0):
                self._map[tmp]._nourriture -= 1
        self._action._define = -1

    def takeObject(self):
        i = self._lenMapX * self._posY + self._posX
        j = 0
        while j < self._action._secondAction.__len__():
            if (self._action._secondAction[j] == self._action._PossibleAction._linemate and self._map[i]._linemate > 0):
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

    def findGoodMove(self):
        if (self._inventaire._nourriture < 5):
            tab = self.findFood(3)
            if (tab[0] == -1 or tab[1] == -1):
                 self.avance()
                 self.voir()
            else:
                self._action.setMove(tab[0], tab[1], self._action._PossibleAction._nourriture, 3)
        else:
            self.takeObject()
        if (self._posX == self._action._x and self._posY == self._action._y and self._action._define == 0):
            self.takeObjectif()
        elif ((self._posX != self._action._x or self._posY != self._action._y) and self._action._define == 0):
            self.moveToAction()
        else:
            self.avance()
            self.voir()
            self.decideCaseToGo()

    def treatOk(self, trame):
        if trame == "ok" or trame == "ko":
            tmp = self._queue.get()
            if tmp.split(' ')[0] == "prend" and trame == "ok":
                self._inventaire.addOne(tmp.split(' ')[1].split('\n')[0])
        print "nouriture = ", self._inventaire._nourriture
