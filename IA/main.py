#!/usr/bin/python

import select
import socket
import time
import sys
from optparse import OptionParser
from player import *

connexion = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

connexion.connect(('', 4242))

myPlayer = player(10, 10, connexion, "team1")
inputs = [connexion]
outputs = []
timeout = 0.1

myPlayer.connect()

while 42 :
    inputready,outputready,exceptready = select.select(inputs, outputs, [], timeout)
    if not (inputready or outputready or exceptready):
        myPlayer.findGoodMove()
    else:
        for s in exceptready:
            sys.exit()
        for s in inputready:
            if s == connexion:
                answer = connexion.recv(1000)
                if (len(answer) == 0):
                    print "Server Disconnected"
                    sys.exit()
                tab = answer.split('\n')
                i = 0
                while i < tab.__len__():
                    if (tab[i] == "mort\n"):
                        sys.exit()
                    elif (tab[i][0:2] == "{ "):
                        myPlayer.changeMapVoir(tab[i])
                    elif (tab[i][0:1] == '{'):
                        myPlayer.modifieInventaire(tab[i])
                    else:
                        myPlayer.treatOk(tab[i])
                    i = i + 1
            else:
                print "Server Disconnected"
                sys.exit()

connexion.close()
