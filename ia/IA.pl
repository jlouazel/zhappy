#!/usr/bin/env perl

use IA;
use strict;

use Getopt::Std;
use vars qw ($opt_n $opt_h $opt_p);

getopts ('n:h:p:');

my $team = $opt_n if ( defined $opt_n);
my $host = $opt_h if ( defined $opt_h );
my $port = $opt_p if ( defined $opt_p );

usage() unless( defined $team && defined $host &&  defined $port );

sub usage
{
	print "Usage : ./IA.pl [-n TEAMNAME] [-h HOST] [-p PORT]\n";
	exit 1;
}

my $ia = IA->new($team, $host, $port);
