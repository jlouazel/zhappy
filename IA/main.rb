#!/usr/bin/env ruby

require 'optparse'

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

begin
	if ARGV.size < 6 then
		raise ArgumentError, 'Not enought arguments provided'
	end
	if ARGV.size > 6 then
		raise ArgumentError, 'Too many arguments provided'
	end
	options = OptparseArgs.parse(ARGV)
	printf("Team : %s, Host : %s, Port : %d\n", options[:team], options[:host], options[:port])
	bot = IA.new(options[:team], options[:host], options[:port])
rescue => e
	puts "An error occured (" + e + ")"
	puts "Usage: ./IA.rb [-n team_name] [-h hostname] [-p port]"
end
