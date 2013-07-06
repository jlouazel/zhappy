#!/usr/bin/python

class   need:
    def __init__(self, linemate, deraumere, sibur, mendiane, phiras, thystame, joueur):
        self._linemate = linemate
        self._deraumere = deraumere
        self._sibur = sibur
        self._mendiane = mendiane
        self._phiras = phiras
        self._thystame = thystame
        self._joueur = joueur

class   elevation:
    def __init__(self):
        self._lvl = []
        self._lvl.append(need(1, 0, 0, 0, 0, 0, 1))
        self._lvl.append(need(1, 1, 1, 0, 0, 0, 2))
        self._lvl.append(need(2, 0, 1, 0, 2, 0, 2))
        self._lvl.append(need(1, 1, 2, 0, 1, 0, 4))
        self._lvl.append(need(1, 2, 1, 3, 0, 0, 4))
        self._lvl.append(need(1, 1, 2, 0, 1, 0, 4))
        self._lvl.append(need(1, 2, 3, 0, 1, 0, 6))
        self._lvl.append(need(2, 2, 2, 2, 2, 1, 6))
        self._allNeed = need(10, 9, 12, 5, 7, 1, 6)

    def getNeed(self, lvl):
        return self._lvl[lvl - 1]
