#!/usr/bin/perl -w

use sigtrap;
use IO::Socket;

$port = $ARGV[0];

$server = IO::Socket::INET->new(LocalPort => $port,
				Type => SOCK_STREAM,
				Reuse => 1,
				Listen => SOMAXCONN)
  || die "Couldn't set up server on port $port: $!\n";

while (1) {
  $client = $server->accept() || die "Couldn't accept new client: $!\n";
  $other_end = $client->peername();
  ($port,$iaddr) = unpack_sockaddr_in($other_end);
  $actual_ip = inet_ntoa($iaddr);
  $hostname = gethostbyaddr($iaddr, AF_INET);
  print "Connection from $actual_ip:$port (host $hostname)\n";
  while (<$client>) {
    $line = $_;
    print "Echoing:$line";
    print $client $line;
  }
}
