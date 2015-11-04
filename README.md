Installation
============

Merge your `~/.bash_profile` and `~/.gitconfig` into `conf/dot-bash_profile` and
`conf/dot-gitconfig`, respectively.  Replace all instances of "/PATH/TO/" with
the full path of this repo.  (On the command line, you can get the full path
with `pwd`.)  If you're in Sublime Text on OS X, you can use ⌘⇧F to search the
whole `conf` directory.  Then:

	mv .bash_profile .bash_profile.old
	mv .gitconfig .gitconfig.old
	ln -s /PATH/TO/jr-config/conf/dot-bash_profile .bash_profile
	ln -s /PATH/TO/jr-config/conf/dot-gitconfig .gitconfig
    brew install git bash-completion
	make
	sudo patch /usr/local/etc/bash_completion.d/git-prompt.sh conf/git-prompt.sh.patch

You'll immediately have access to all the Git aliases and configuration.  To get
the Bash configuration, close and reopen all your shells, or run `bash -l` to
spawn a new subshell.

Updating Git prompt
===================

If conf/git-prompt.sh.patch has changed, run the following to get the new
changes:

	sudo mv /usr/local/etc/bash_completion.d/git-prompt.sh.orig /usr/local/etc/bash_completion.d/git-prompt.sh
	sudo patch /usr/local/etc/bash_completion.d/git-prompt.sh conf/git-prompt.sh.patch
	source /usr/local/etc/bash_completion.d/git-prompt.sh

But I Don't Like It
===================

If you don't want to use this tool, that's fine.  But please at least do this:

    git config --global push.default tracking

Also, you might want to look around this repo for useful stuff to incorporate
into your own system configuration.

Updating from Upstream
======================

First-time configuration
------------------------

    git remote add upstream git@github.com:divitu/

Update
------

    git fetch upstream

If `master` did not advance, there is nothing to update.  Otherwise:

    git checkout master  #-- if you're not already on master
    git merge --no-edit --no-ff upstream/master
