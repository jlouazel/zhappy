#!/usr/bin/env perl

use IA;
use strict;

use Getopt::Std;
use vars qw ($opt_n $opt_h $opt_p);

# parsing des arguments
getopts ('n:h:p:');

my $team = $opt_n if ( defined $opt_n);
my $host = $opt_h if ( defined $opt_h );
my $port = $opt_p if ( defined $opt_p );

# affige l'usage en cas d'arguments incomplets et / ou invalides
usage() unless( defined $team && defined $host &&  defined $port );

sub usage
{
	print "Usage : ./IA.pl [-n TEAMNAME] [-h HOST] [-p PORT]\n";
	exit 1;
}

# instanciation d'une IA
my $ia = IA->new($team, $host, $port);
$ia->authenticate();
