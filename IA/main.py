#!/usr/bin/python

import select
import socket
import time
import sys
import traceback

from optparse import OptionParser
from player import *

try:
	print "JE SUIS EN TRAIN DE ME LANCER"
	connexion = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	usage = "usage: %prog -n TeamName -p Port -h MachineName"
	parser = OptionParser(add_help_option=False)

	parser.add_option("-n", "--teamName", dest="teamName", help="Write a Team's Name")
	parser.add_option("-p", "--port", dest="port", help="Write a port")
	parser.add_option("-h", "--host", dest="host", help="Write an host")
	parser.add_option("-H", "--help", action="store_true", help='show this help message')

	(options, args) = parser.parse_args()
	if options.help or options.teamName == None or options.port == None or options.host == None:
	    parser.print_help()
	    sys.exit()

	teamName = options.teamName
	port = options.port
	host = options.host

	connexion.connect((host, int(port)))

	myPlayer = player(connexion, teamName, port, host)
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
	                        print "Je suis mort."
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
except:
	print "Exception in user code:"
	print '-'*60
	traceback.print_exc(file=sys.stdout)
	print '-'*60
