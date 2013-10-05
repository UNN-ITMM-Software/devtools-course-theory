for dir in */; 
do
    echo
    echo "Testing $dir"

    cd $dir

    if [ -f Makefile ];
    then
       echo "Makefile exists"
       make test
    else
       echo "No Makefile"
    fi

    cd ..
done