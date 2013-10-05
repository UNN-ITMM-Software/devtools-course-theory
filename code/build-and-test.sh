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

# Go through all directories and run 'make test'
for dir in */; 
do
    echo && echo "Testing $dir"
    cd $dir

    if [ -f Makefile ];
    then
       echo "Makefile exists"
       try make test
    else
       echo "No Makefile"
    fi

    cd ..
done