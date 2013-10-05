function test_command {
    "$@"
    status=$?
    if [ $status -ne 0 ]; then
        echo "ERROR with $1"
        exit $status
    fi
    return $status
}

for dir in */; 
do
    echo
    echo "Testing $dir"

    cd $dir

    if [ -f Makefile ];
    then
       echo "Makefile exists"
       test_command make test
    else
       echo "No Makefile"
    fi

    cd ..
done