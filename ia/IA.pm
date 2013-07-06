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

sub authenticate {
	my ($this) = @_;
	my $buf = "";
	my @array = ();
	# reception du "BONJOUR\n"
	$this->{socket}->recv($buf, 2048);
	sleep(0.05);
	# envoi du nom d'equipe
	$this->{socket}->send($this->{teamname}."\n");
	sleep(0.05);
	# reception de l'id
	$this->{socket}->recv($buf, 2048);
	$this->{id} = substr($buf, 0, -1);
	sleep(0.05);
	# reception de la taille de la map
	$this->{socket}->recv($buf, 2048);
	@array = split(/ /, substr($buf, 0, -1));
	$this->{max_x} = @array[0];
	$this->{max_y} = @array[1];
	print "Je suis le ".$this->{id}."eme joueur de l'equipe ".$this->{teamname}." et le monde fait ".$this->{max_x}." x ".$this->{max_y}."\n";
}
1;