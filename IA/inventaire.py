#!/usr/bin/python

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

    def delOne(self, string):
        if (string == "linemate"):
            self._linemate -= 1
        if (string == "deraumere"):
            self._deraumere -= 1
        if (string == "sibur"):
            self._sibur -= 1
        if (string == "mendiane"):
            self._mendiane -= 1
        if (string == "phiras"):
            self._phiras -= 1
        if (string == "thystame"):
            self._thystame -= 1
        if (string == "nourriture"):
            self._nourriture -= 1

    def howMany(self, string):
        if (string == "linemate"):
            return self._linemate
        if (string == "deraumere"):
            return self._deraumere
        if (string == "sibur"):
            return self._sibur
        if (string == "mendiane"):
            return self._mendiane
        if (string == "phiras"):
            return self._phiras
        if (string == "thystame"):
            return self._thystame
        if (string == "nourriture"):
            return self._nourriture

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
