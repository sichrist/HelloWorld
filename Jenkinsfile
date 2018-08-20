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