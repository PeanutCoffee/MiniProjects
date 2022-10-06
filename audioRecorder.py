import sounddevice as sd
from scipy.io.wavfile import write
import wavio as wv


from pydub import AudioSegment
from os import path


#sampling frequency
freq = 44100

#recording duration in seconds
duration = 60

#start recorder with given values of duration and frequency
recording = sd.rec(int(duration * freq), samplerate=freq, channels=2)

sd.wait()

#save the audio
write("testAudio0.wav", freq, recording)
wv.write("testAudio1.wav", recording, freq, sampwidth=2)


# if you want to convert f.wav file in .mp3
#sound = AudioSegment.from_mp3('testAudio0.wav')
#sound.export('testAudio0.mp3', format="wav")
