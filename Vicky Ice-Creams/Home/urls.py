from django.contrib import admin
from django.urls import path
from Home import views

urlpatterns = [
    path("", views.index, name='Home'),
    path("about", views.about, name='about'),
    path("IceCreams", views.IceCreams, name='IceCreams'),
    path("contact", views.contact, name='contact')
]
