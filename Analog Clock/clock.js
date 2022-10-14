setInterval(() => {
    dt = new Date();
    htime = dt.getHours();
    mintime= dt.getMinutes();
    sectime= dt.getSeconds();
    hrrotation = 30*htime + mintime/2;
    minrotation = mintime*6 ;
    secrotation= sectime*6;
    hour.style.transform=`rotate(${hrrotation}deg)`;
    minute.style.transform=`rotate(${minrotation}deg)`;
    second.style.transform=`rotate(${secrotation}deg)`;
}, 1000);

