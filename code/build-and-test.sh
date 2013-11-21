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

function Header {
    echo ""
    echo "*****************************************************"
    echo "$@"
    echo "*****************************************************"
    echo ""
}

function CheckGoogleStyleInDir {
    retCode=0

    hpp_files=`find . -name "*.hpp"`
    if [ $hpp_files ]; then
        echo "ERROR: Please use *.h extension instead of *.hpp:"
        echo " - $hpp_files"
        retCode=1
    fi

    sources=`find . -name "*.hpp" -or -name "*.h" -or -name "*.cpp"`
    for file in $sources;
    do
        echo "Analysing $file"
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
    for dir in */;
    do
        cd $dir

        Header "Check \"Google C++ Style\" in $dir"
        try CheckGoogleStyleInDir

        cd ..
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
    # Build common CMake project
    Header "Test common CMake project"

    cmake_build_dir="../build_cmake"
    $dir=$cmake_build_dir
    mkdir $cmake_build_dir
    cd $cmake_build_dir
    try cmake ../code && make
}

function CTest {
    try ctest --output-on-failure
}

function Main {
    CheckGoogleStyle
    MakeTest
    BuildCMakeProject
    CTest
}

Main