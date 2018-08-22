#!groovy
pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make && make HelloWorld_coverage'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'                
                echo 'Run Test ..'
                sh 'build/HelloWorld_test --gtest_output=xml'
            }
        }

        stage('Linting'){
            steps{
                echo 'Linting..'
                sh 'cppcheck -v --enable=all --std=c++11 --xml --xml-version=2 -I include/ src/ include/ 2> result_cppcheck.xml && cat result_cppcheck.xml'
                sh 'rats -w 3 --xml src/*.cpp include/*.h > rats_report.xml'
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