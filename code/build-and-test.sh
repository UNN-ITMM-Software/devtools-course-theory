# This function executes command and stops 
# exectution if return status wasn't 0
function try {
    "$@"
    status=$?
    if [ $status -ne 0 ]; then
        echo "ERROR with '$@' in $dir"
        exit $status
    fi
    return $status
}

function print {
    echo ""
    echo "$@"
    echo "---------------------------"
    echo ""
}

# Go through all directories and run 'make test'
for dir in */; 
do
    echo ""
    echo "*****************************************************"
    echo "Testing $dir"
    echo "*****************************************************"

    cd $dir

    print "Check Google-style"
    find . -name "*.h" -or -name "*.hpp" -or -name "*.cpp" | xargs python ../cpplint.py

    print "Build and test"
    if [ -f Makefile ];
    then
       echo "Makefile exists"
       try make test
    else
       echo "No Makefile"
    fi

    cd ..
done