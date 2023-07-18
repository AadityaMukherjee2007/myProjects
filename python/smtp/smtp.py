import os
from sendgrid import SendGridAPIClient
from sendgrid.helpers.mail import Mail

message = Mail(
    from_email='t6826461@gmail.com',
    to_emails='t6826461@gmail.com',
    subject='Sending with Twilio SendGrid is Fun',
    html_content='<strong>and easy to do anywhere, even with Python</strong>')

sg = SendGridAPIClient(os.environ.get('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'))
response = sg.send(message)
print(response.status_code, response.body, response.headers)
