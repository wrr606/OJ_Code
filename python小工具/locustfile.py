from locust import HttpUser, task, between

class MyUser(HttpUser):
    wait_time = between(1, 2)

    @task
    def index(self):
        self.client.get("/")

    @task
    def about(self):
        self.client.get("/idx")