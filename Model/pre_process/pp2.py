import requests

import matplotlib.pyplot as plt
from PIL import Image
from io import BytesIO

subscription_key = "52f230c9447245fd9904c3be11cf22f8"
assert subscription_key

vision_base_url = "https://westcentralus.api.cognitive.microsoft.com/vision/v2.0/"

analyze_url = vision_base_url + "analyze"
analyze_url = vision_base_url + "recognizeText"

image_path = "MyImage.jpg"

image_data = open(image_path, "rb").read()
headers    = {'Ocp-Apim-Subscription-Key': subscription_key,
              'Content-Type': 'application/octet-stream'}
params     = {'visualFeatures': 'Categories,Description,Color'}



headers = {'Ocp-Apim-Subscription-Key': subscription_key}
params  = {'mode': 'Handwritten'}
data    = {'data': image_data}
response = requests.post(
    analyze_url, headers=headers, params=params, data=image_data)
    
analysis = response.json()
print(analysis)
image_caption = analysis["description"]["captions"][0]["text"].capitalize()

image = Image.open(BytesIO(image_data))
plt.imshow(image)
plt.axis("off")
_ = plt.title(image_caption, size="x-large", y=-0.1)

plt.show()