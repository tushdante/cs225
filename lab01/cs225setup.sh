#!/bin/bash
mkdir ~/bin 2> /dev/null
echo '#!/bin/bash
echo -e '\''Useful linux commands:

\033[35mpwd\033[0m             Print Working Directory - shows the folder you are currently in

\033[35mls\033[0m              List - lists the files in your current folder

\033[35mcd\033[30m FOLDER\033[0m       Change Directory to FOLDER - opens FOLDER
\033[35mcd\033[30m ..\033[0m            - opens the parent folder of your current location
\033[35mcd\033[30m ~\033[0m             - opens  your home folder

\033[35mgedit\033[30m FILE \033[35m&\033[0m    Opens (or creates) FILE in a text editor

\033[35mrm\033[30m FILE\033[0m         Remove - deletes FILE
\033[35mrm -r\033[30m FOLDER\033[0m           - deletes a folder and its contents
\033[35mmv\033[30m FILE1 FILE2\033[0m  Move - moves/renames FILE1 to FILE2
\033[35mcp\033[30m FILE1 FILE2\033[0m  Copy - copies FILE1 to FILE2

\033[35mmake\033[30m PROGRAM\033[0m    Compiles PROGRAM using the rules in the Makefile file

\033[35mgthumb\033[30m IMAGE \033[35m&\033[0m  Opens IMAGE in an image viewer

\033[35mreset\033[0m           Reset and clear the terminal
'\' > ~/bin/help
chmod u+x ~/bin/help

# Update the .cshrc file
echo "" >> ~/.cshrc
/bin/cp ~/.cshrc ~/.cshrc_backup --backup=numbered
echo '# EWS .cshrc Template - Modified for CS 225
#
# This file is executed each time you start up a new C shell (/bin/csh).
#
# The following line executes the default profile script for the workstation
# platform you are using.  This script sets up various environment variables
# such as the search path and performs other functions.
# DO NOT REMOVE THIS LINE!!
#
source /usr/local/ews/system.cshrc
#
# The above script defines a variable called ENVIRON which is set to either
# HPDOMAIN, HPUX, SUN, or RS6000.  You can use this variable to determine
# which platform you are using so that you can execute system-specific 
# commands.  For example:
#
# if ( $ENVIRON == SUN ) then
#   ...do Sun stuff here
# endif 
#
# If you want to modify an environment variable, for example, the search
# path, take into account the value that the variable already has.  For example
# if you wish to add the directory /local/apps1/cl to your search path,
# you would use
#
# set path=($path /local/apps1/cl)
#
# This merely appends the directory /local/apps1/cl to the already-existing
# search path.
#
# You can also create aliases for often-used commands.  For example, if you
# would prefer to type '\''dir'\'' instead of '\''ls -FC'\'', you could use
#
# alias dir '\"'ls -FC'\"'
#
# so that each time you typed '\''dir'\'', it would be as though you had typed
# '\''ls -FC'\''
#

set prompt = '\"'%c2'\\'> '\"'
alias cp '\''cp -i'\''
alias mv '\''mv -i'\''
alias make '\''make --warn-undefined-variables'\''
set path=(. $home/bin $path)
set path=(. /home/engr/cs225/bin $path)
' > ~/.cshrc

# Create a simple .vimrc
echo "" >> ~/.vimrc
/bin/cp ~/.vimrc ~/.vimrc_backup --backup=numbered
echo 'set nocompatible
set tabstop=4
set shiftwidth=4
set expandtab
set softtabstop=4
autocmd FileType make setlocal noexpandtab
set smartindent
set autoindent
set incsearch
set ignorecase
set smartcase
set scrolloff=2
set wildmode=longest,list' > ~/.vimrc

# Turn emacs syntax highlighting on
echo "" >> ~/.emacs
/bin/cp ~/.emacs ~/.emacs_backup --backup=numbered
echo '(global-font-lock-mode 1)' >> ~/.emacs

# Update SVN editor if unset
sed -i 's/# editor-cmd = editor (vi, emacs, notepad, etc.)/editor-cmd = gedit\n# (vim, gedit, emacs, etc.)/' ~/.subversion/config

echo 'Please close your terminal and open a new one for these settings to take effect'

