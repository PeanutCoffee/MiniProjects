from django.shortcuts import render, HttpResponse
from datetime import datetime
from Home.models import Contact
from django.contrib import messages

# Create your views here.
def index(request):
    return render(request, "index.htm")
    # return HttpResponse("This is Homepage")

def about(request):
    return render(request, "about.htm")
    # return HttpResponse("This is About Page")

def IceCreams(request):
    return render(request, "IceCreams.htm")
    # return HttpResponse("This is Services Section")

def contact(request):
    if request.method == "POST":
        email = request.POST.get('email')
        message = request.POST.get('message')
        contact = Contact(email=email, message=message, date = datetime.today())
        contact.save()
        messages.success(request, 'Your Message Has Been Sent !')
    return render(request, "contact.htm")
    # return HttpResponse("This is Contact Page")