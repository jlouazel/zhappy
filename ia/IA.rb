#!/usr/bin/env ruby

require 'socket'

class IA
	attr_reader :team
	attr_reader :socket
	attr_writer :socket
	
	def initialize(team, host, port)
		@team = team
		@socket = TCPSocket.new host, port
	end
end
