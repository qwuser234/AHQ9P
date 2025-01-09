#!/bin/env perl

use warnings;
use strict;
use Cwd;

die "you must is script run from root!" if $> != 0;

print qq(
     mm   m    m  mmmm   mmmm
    ##   #    # m"  "m #"  "m   m
  #  #  #mmmm# #    # #m  m#    #
 #mm#  #    # #    #  """ #  """#"""
#    # #    #  #mm#" "mmm"      #
                 #
);

print "\nAHQ9+ - Andriy Own HelloworldQuine99bottlesofbeeronthewall+increment Compiler on GPL Licence And make on C++17!\n";
print "Install source code <main.cpp> on /usr/src[y] or remove[n]?, for cancel installation press other key(enter is also other key.) - <y/n/[other key]> - ";

my $curdir = cwd();

my $input = <STDIN>;
chomp $input;

if ($input eq "n") {
    print "removing only binary[b] or source-binary[a] or only source[s]?\n";
    my $sl = <STDIN>;
    chomp $sl;

    if ($sl eq "b") {
        print "removing a binary file [/usr/bin/ahq9pc]\n";
        `rm -rf /usr/bin/ahq9pc`;
        print "deleted \n";
    } elsif ($sl eq "a") {
        print "removing a binary and source code [/usr/src/ahq9p/main.cpp|/usr/bin/ahq9pc]\n";
        `rm -rf /usr/src/ahq9p`;
        `rm -rf /usr/src/ahq9pc`;
        print "deleted\n";
    } elsif ($sl eq "s") {
        print "removing a source code [/usr/src/ahq9p/main.cpp]\n";
        `rm -rf /usr/src/ahq9p/main.cpp`;
        print "deleted\n";
    } else {
        die "only <b/a/s>\n";
    }
} elsif ($input eq "y") {
    print "installation ahq9p on your pc ;3\n";
    print "Make dir: /usr/src/ahq9p/\n";
    `mkdir -p /usr/src/ahq9p/bin/&>/dev/null`;
    print "Copy main.cpp in /usr/src/ahq9p/\n";
    `cp -v $curdir/main.cpp /usr/src/ahq9p/&>/dev/null`;
    print "Comiling ahq9p to binary and copy then on /usr/bin\n";
    `g++ -pipe -std=c++17 -O2 -Wall /usr/src/ahq9p/main.cpp -o /usr/src/ahq9p/bin/ahq9pc`;
    `ln -s /usr/src/ahq9p/bin/ahq9pc /bin/ahq9pc&>/dev/null`;
    print "ahq9p installed on your pc! for use just write in your shell: ahq9pc\n";
} else {
    die "installation cancel.\n";
}
