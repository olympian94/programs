#Execute this script from the folder containing the junit*.jar file and hamcrest*.jar file
#Download the above mentioned files from "Download And Install" link at http://junit.org/

sudo mkdir /usr/local/JUNIT;
sudo cp junit*.jar /usr/local/JUNIT/;
sudo cp hamcrest*.jar /usr/local/JUNIT/;
#create new JUNIT_HOME environment variable for JUnit
export JUNIT_HOME=/usr/local/JUNIT;
#set CLASSPATH variable for JUnit
export CLASSPATH=$CLASSPATH:$JUNIT_HOME/junit*.jar:$JUNITHOME/hamcrest*.jar:.
echo "DOne. Now you can use JUnit for your UnitTesting";
