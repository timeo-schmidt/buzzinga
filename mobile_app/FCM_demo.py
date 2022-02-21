# Install the PyFCM library
# -> run in your terminal:  $pip3 install pyfcm

# Import the PyFCM library to the script
from pyfcm import FCMNotification

# Initialize the Firebase Cloud Messaging service (using the API key that is provided):
push_service = FCMNotification(api_key="AAAAKj2r-d0:APA91bEbp-oXiE9u7ubZjdvm2zJ8C_ZyCu-HnNACwiGRoRRip5GpRXBq7_v68zN-VQ4FP_tEsdkzj3SINnT6EBVN7NP9_VbfuVlN7y4x8x8z-uipPq_9upZTXyyrqik9Yh2mJKEBsj0o")

# Sending a visible device notification (this is what the user will see in the POP-UP NOTIFICATION / in his NOTIFICATION CENTRE)
message_title = "Notification Title"
message_body = "Notification Body"

# ... with data message payload (this is what the user will see IN THE APP)
data_message = {                  
    "title" : "Title",
    "content" : "Content",
    "category" : "Category",
    "author" : "Author"
}

# ... to devices subscribed to a topic.
topic_name = "test_test"
result = push_service.notify_topic_subscribers(topic_name=topic_name, message_body=message_body, message_title=message_title, data_message=data_message, content_available=True)

print(result)