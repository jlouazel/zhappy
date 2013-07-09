#!/usr/bin/python

class   defineAction:
    def __init__(self):
        self._undifined = -1
        self._nourriture = 0
        self._linemate = 1
        self._deraumere = 2
        self._sibur = 3
        self._mendiane = 4
        self._phiras = 5
        self._thystame = 6
        self._incantation = 7
        self._incantationEnnemy = 8

class   action:
    def __init__(self):
        self._define = -1
        self._x = 0
        self._y = 0
        self._PossibleAction = defineAction()
        self._tabPossibleAction = ["nourriture", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame", "incantation", "incantationEnnemy"];
        self._firstAction = self._PossibleAction._undifined
        self._secondAction = []
        self._thirdAction = []
        self._emergency = 1
# 1 = importance basse action 1, 2 et 3 seront executer en parallele du deplacement. 2 = importance moyenne seulement l'action 1 et 2 seront executer. 3 = importance haute seulement l'acion 1.

    def setMove(self, x, y, action1, emergency):
        self._define = 0
        self._x = x
        self._y = y
        self._firstAction = action1
        self._emergency = emergency

    def initSecondAction(self):
        self._secondAction = []

    def addSecondAction(self, secondAction):
        i = 0
        flag = False
        while i < self._secondAction.__len__():
            if self._secondAction[i] == secondAction:
                flag = True
            i = i + 1
        if flag != True:
            self._secondAction.append(secondAction)

    def delSeconAction(self, toDel):
        i = 0
        while i < self._secondAction.__len__():
            if self._secondAction[i] == toDel:
                i = 0
                self._secondAction.remove(self._secondAction[i])
            else:
                i = i + 1

    def affSecondAction(self):
        i = 0
        print "["
        while i < self._secondAction.__len__():
            print self._tabPossibleAction[self._secondAction[i]], " "
            i = i + 1
        print "]"

    def addThirdAction(self, thirdAction):
        if thirdAction in self._thirdAction == False:
            self._thirdAction.append(thirdAction)

    def delThirdAction(self, toDel):
        i = 0
        while i < self._thirdAction.__len__():
            if self._thirdAction[i] == toDel:
                self._thirdAction.remove(self._thirdAction[i])
            i = i + 1
