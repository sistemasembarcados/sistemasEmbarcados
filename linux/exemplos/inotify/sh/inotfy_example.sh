#!/bin/bash

# apt-get install inotify-tools

NOTIFYDIR="/tmp"
inotifywait -r -m $NOTIFYDIR -e modify,attrib,close_write,move,create,delete | while read path action file; do
	echo "Acao: $action - ${path}${file}"
done 
