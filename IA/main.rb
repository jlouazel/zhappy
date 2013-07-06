#!/usr/bin/env ruby

require 'optparse'
require 'IA'

class OptparseArgs
	def self.parse(args)
		options = {}
		opt_parser = OptionParser.new do |opts|
			opts.on('-n TEAM') do |team|
        		options[:team] = team
        	end
        	opts.on('-h HOST') do |host|
        		options[:host] = host
        	end
        	opts.on('-p PORT') do |port|
        		options[:port] = Integer(port)
        	end
        end
    opt_parser.parse!(args)
    options
    end
end

# "try" facon ruby
begin
	# gestion du nombre d'arguments
	if ARGV.size < 6 then
		raise ArgumentError, 'Not enought arguments provided'
	end
	if ARGV.size > 6 then
		raise ArgumentError, 'Too many arguments provided'
	end
	
	# parsing des arguments
	options = OptparseArgs.parse(ARGV)
	
	# instantiation d'une IA
	bot = IA.new(options[:team], options[:host], options[:port])
	
	# boucle pour la socket client 
	connected = true
	while connected == true do
		bot.socket.puts("Keukou")
		connected = false
	end
	puts "You have been disconnected"
	
# "catch" facon ruby
rescue => e
	puts "An error occured (" + e + ")"
	puts "Usage: ./IA.rb [-n team_name] [-h hostname] [-p port]"
end
