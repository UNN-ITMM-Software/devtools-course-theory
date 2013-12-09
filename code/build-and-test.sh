cmake_build_dir="../build_cmake"

function try {
# This function executes command and stops 
# exectution if return status wasn't 0
    "$@"
    status=$?
    if [ $status -ne 0 ]; then
        echo "ERROR with '$@' in $dir"
        exit $status
    fi
    return $status
}

function Header {
    echo ""
    echo "*****************************************************"
    echo "$@"
    echo "*****************************************************"
    echo ""
}

function CheckGoogleStyleInDir {
    retCode=0

    # hpp_files=`find . -name "*.hpp"`
    # if [[ $hpp_files ]]; then
    #     echo "ERROR: Please use *.h extension instead of *.hpp:"
    #     echo " - $hpp_files"
    #     retCode=1
    # fi

    echo "Checking $dir"
    sources=`find . -name "*.hpp" -or -name "*.h" -or -name "*.cpp"`
    for file in $sources;
    do
        python ../cpplint.py $file
        status=$?
        if [ $status -ne 0 ]; then
            retCode=$status
        fi
    done

    return $retCode
}

function CheckGoogleStyle {
    # Go through all directories and check Google style
    Header "Check \"Google C++ Style\""

    for dir in */;
    do
        if [ "$dir" == "3rdparty/" ]; then
            continue
        fi

        cd $dir
        try CheckGoogleStyleInDir
        cd ..
        echo ""
    done
}

function MakeTest {
    # Go through all directories and run 'make test'
    for dir in */;
    do
        cd $dir

        Header "Build and Test $dir"
        if [ -f Makefile ];
        then
           echo "Makefile exists"
           try make test
        else
           echo "No Makefile"
        fi

        cd ..
    done
}

function BuildCMakeProject {
    Header "Build common CMake project"

    dir=$cmake_build_dir
    mkdir $cmake_build_dir
    cd $cmake_build_dir
    try cmake ../code
    try make
}

function CTest {
    Header "Run all CTest tests"
    try ctest --output-on-failure
}

function GoogleTest {
    Header "Run all GoogleTest tests"

    for test in $(ls -1 ./bin/*-test)
    do
        Header "Testing $test"
        try $test
    done
}

function Clean {
    rm -rf $cmake_build_dir
}

function Main {
    Clean
    CheckGoogleStyle
    MakeTest
    BuildCMakeProject
    CTest
    GoogleTest
}

Main
