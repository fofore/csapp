#!/usr/bin/perl -w

use sigtrap;
use IO::Socket;

$host = $ARGV[0];
$port = $ARGV[1];

autoflush STDOUT 1;

$socket = IO::Socket::INET->new("$host:$port")
  || die("Couldn't connect to $host:$port: $!\n");


print "type:";
while (<STDIN>) {
  $line = $_;
  print $socket $line;
  $reply = <$socket>;
  print "echo:$reply";
  print "type:";
}

