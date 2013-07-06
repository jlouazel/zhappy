#!/usr/bin/python

class case:
    def __init__(self):
        self._linemate = 0
        self._deraumere = 0
        self._sibur = 0
        self._mendiane = 0
        self._phiras = 0
        self._thystame = 0
        self._nourriture = 0
        self._probabilities = 0

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
        self._probabilities = self._probabilities - 2
