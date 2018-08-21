#!groovy
pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'mkdir -p build && cd build && scan-build cmake .. && scan-build -plist --use-cc=clang --use-c++=clang++ -o ./scanbuildout/ make'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'                
                echo 'Run Test ..'
                sh 'build/testrun --gtest_output=xml'
            }
        }

        stage('Linting'){
            steps{
                echo 'Linting..'
                sh 'cppcheck -v --enable=all --xml --xml-version=2 -I include/ --check-config src/ include/ test/ 2> result_cppcheck.xml'
                sh 'rats -w 3 --xml src/ include/ > rats_report.xml'
            }
        } 
        stage('SonarQube analyzing...'){
            steps{
                sh '/opt/sonar-scanner/bin/sonar-scanner -X'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
        stage('Clean'){
            steps{
                echo 'Cleaning.....'
                sh 'tree'
                sh 'rm -rf build'
                sh 'rm *.xml'
            }
        }
    }
}