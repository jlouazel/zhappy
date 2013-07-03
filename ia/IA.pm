#!/usr/bin/env perl

package IA;
use strict;
use IO::Socket;

sub new {
 my ($class, $teamname, $host, $port) = @_;
 my $this = {};
 bless ($this, $class);
 $this->{teamname}= $teamname;
 $this->{socket} = IO::Socket::INET->new(Proto => "tcp", PeerAddr => $host, PeerPort => $port) || die "Failed : $!";
 $this->{socket}->autoflush(1);
 return $this;
}
1;