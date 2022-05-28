#! /bin/zsh

########################################
# Run links. If print is called, use   #
# fzf to allow us to choose a main and #
# sub class, then run ol again         #
########################################

# Directory where shell script lives
BASEDIR=$(dirname "$0")

# if they pass in print 
if [[ $1 = "print" ]]
then
    # Execute ./main print
    exec $BASEDIR/main print | # Execute ./main print
        grep ":" | # grab all classes, subclasses, links & put them into
        paste -d " " - - - | # format  
        sed -e "s/theClass : //g" | # formatting
        sed -e "s/ subClass : /->/g" | # formatting
        sed -e "s/ link : /->/g" | # formatting
        fzf | # fzf grouped together
        sed -e "s/->/\n/g" | # Turn arrows into new lines
        grep "\." | # find the line w/ a .
        sed -e 's/[[:space:]]\+$//' | # Remove trailing white spaces
        sed -e 's/^[ \t]*//' | # Remove all leading white spaces
        $BASEDIR/main # Rerun main w/ stdin to open website
else
    exec $BASEDIR/main "$@" # Run links normally 
fi

