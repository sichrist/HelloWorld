#!groovy
pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'mkdir -p build'
                sh 'cd build'
                sh 'ls -l'
                sh 'cmake ..'
                sh 'cd ..'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}