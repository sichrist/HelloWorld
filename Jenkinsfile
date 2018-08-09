#!groovy
pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'mkdir -p build && cd build && cmake .. && make && ./hello'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('SonarQube analyzing...'){
            steps{
                sh 'sonar-scanner'
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