#!groovy
pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'mkdir -p build && cd build && cmake .. && make'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                echo 'Run Binary ..'
                sh 'build/HelloWorld'
                echo 'Run Test ..'
                sh 'build/testrun --gtest_output=xml'
            }
        }

        stage('Linting'){
            steps{
                echo 'Linting..'
                sh 'cppcheck --enable=all --inconclusive --std=posix -q --xml --xml-version=2 -I include/ --check-config src/ include/ test/ 2> result_cppcheck.xml'
                sh 'rats -w 3 --xml src/ include/ > rats_report.xml'
            }
        } 
        stage('SonarQube analyzing...'){
            steps{
                sh '/opt/sonar-scanner/bin/sonar-scanner'
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
                sh 'rm -rf build'
            }
        }
    }
}