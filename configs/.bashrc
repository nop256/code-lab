# ~/.bashrc: executed by bash(1) for non-login shells.

# Note: PS1 and umask are already set in /etc/profile. You should not
# need this unless you want different defaults for root.
# PS1='${debian_chroot:+($debian_chroot)}\h:\w\$ '
# umask 022

# You may uncomment the following lines if you want `ls' to be colorized:
 export LS_OPTIONS='--color=auto'
#
# Some more alias to avoid making mistakes:
# alias rm='rm -i'
# alias cp='cp -i'
# alias mv='mv -i'

if [ -x /usr/bin/dircolors ]; then
	test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
	alias ls='ls -l'
	alias la='ls -la'
	alias code='cd ~/code'
	alias cdpy='cd ~/code/python'
	alias 2810='cd ~/CS-2810'
	alias 2420='cd ~/CS-2420'
	alias p3i='python3 -i'
    alias cdlab='cd ~/code/code-lab && git pull'
    alias cd3='cd ~/code/cs3005/cs3005-fall-2025-nop256/src && git pull'
    alias cse='cd ~/code/cs2450-youface-fall2025-stay-at-home-wives && git pull'
fi

PS1="\[$(tput setaf 39)\]\u\[$(tput setaf 0)\]@\[$(tput setaf 35)\]\h \[$(tput setaf 39)\]\w \[$(tput sgr0)\]$ "
. "$HOME/.cargo/env"

umask 0022
