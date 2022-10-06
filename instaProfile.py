import instaloader

bot = instaloader.Instaloader()

# username = input('enter username: ');
# profile = instaloader.Profile.from_username(bot.context, username)
profile = instaloader.Profile.from_username(bot.context, 'USER-NAME')

print("Username: ", profile.username)
print("User ID: ", profile.userid)
print("Number of Posts: ", profile.mediacount)
print("Followers: ", profile.followers)
print("Following: ", profile.followees)
print("Bio: ", profile.biography)
print("Link in Bio: ", profile.external_url)
