class Bank:
    def __init__(self):
        self.client_details_list = []
        self.loggedin = False
        self.cash = 100
        self.TranferCash = False

    def register(self, name, ph, password):
        cash = self.cash
        contitions = True
        if len(str(ph)) > 10 or len(str(ph)) < 10:
            print("Invalid Phone number ! please enter 10 digit number")
            contitions = False

        if len(password) < 5 or len(password) > 18:
            print("Enter password greater than 5 and less than 18 character")
            contitions = False

        if contitions == True:
            print("Account created successfully")
            self.client_details_list = [name, ph, password, cash]
            with open(f"{name}.txt", "w") as f:
                for details in self.client_details_list:
                    f.write(str(details)+"\n")

    def login(self, name, ph, password):
        with open(f"{name}.txt", "r") as f:
            details = f.read()
            self.client_details_list = details.split("\n")
            if str(ph) in str(self.client_details_list):
                if str(password) in str(self.client_details_list):
                    self.loggedin = True

            if self.loggedin == True:
                print(f"{name} logged in")
                self.cash = int(self.client_details_list[3])
                self.name = name

            else:
                print("Wrong details")

    def add_cash(self, amount):
        if amount > 0:
            self.cash += amount
            with open(f"{name}.txt", "r") as f:
                details = f.read()
                self.client_details_list = details.split("\n")

            with open(f"{name}.txt", "w") as f:
                f.write(details.replace(
                    str(self.client_details_list[3]), str(self.cash)))

            print("Amount added successfully")

        else:
            print("Enter correct value of amount")

    def Tranfer_cash(self, amount, name, ph):
        with open(f"{name}.txt", "r") as f:
            details = f.read()
            self.client_details_list = details.split("\n")
            if str(ph) in self.client_details_list:
                self.TranferCash = True

        if self.TranferCash == True:
            total_cash = int(self.client_details_list[3]) + amount
            left_cash = self.cash - amount
            with open(f"{name}.txt", "w") as f:
                f.write(details.replace(
                    str(self.client_details_list[3]), str(total_cash)))

            with open(f"{self.name}.txt", "r") as f:
                details_2 = f.read()
                self.client_details_list = details.split("\n")

            with open(f"{self.name}.txt", "w") as f:
                f.write(details_2.replace(
                    str(self.client_details_list[3]), str(left_cash)))

            print("Amount Transfered Successfully to", name, "-", ph)
            print("Balacne left =", left_cash)

    def password_change(self, password):
        if len(password) < 5 or len(password) > 18:
            print("Enter password greater than 5 and less than 18 character")
        else:
            with open(f"{self.name}.txt", "r") as f:
                details = f.read()
                self.client_details_list = details.split("\n")

            with open(f"{self.name}.txt", "w") as f:
                f.write(details.replace(
                    str(self.client_details_list[2]), str(password)))
            print("new Password set up successfully")

    def ph_change(self, ph):
        if len(str(ph)) > 10 or len(str(ph)) < 10:
            print("Invalid Phone number ! please enter 10 digit number")
        else:
            with open(f"{self.name}.txt", "r") as f:
                details = f.read()
                self.client_details_list = details.split("\n")

            with open(f"{self.name}.txt", "w") as f:
                f.write(details.replace(
                    str(self.client_details_list[1]), str(ph)))
            print("new Phone number set up successfully")


if __name__ == "__main__":
    Bank_object = Bank()
    print("Welcome to my Bank")
    print("1.Login")
    print("2.Creata a new Account")
    user = int(input("Make decision: "))

    if user == 1:
        print("Logging in")
        name = input("Enter Name: ")
        ph = int(input("Enter Phone Number: "))
        password = input("Enter password: ")
        Bank_object.login(name, ph, password)
        while True:
            if Bank_object.loggedin:
                print("1.Add amount")
                print("2.Check Balcane")
                print("3.Tranfer amount")
                print("4.Edit profile")
                print("5.Logout")
                login_user = int(input())
                if login_user == 1:
                    print("Balance =", Bank_object.cash)
                    amount = int(input("Enter amount: "))
                    Bank_object.add_cash(amount)
                    print("\n1.back menu")
                    print("2.Logout")
                    choose = int(input())
                    if choose == 1:
                        continue
                    elif choose == 2:
                        break

                elif login_user == 2:
                    print("Balacne =", Bank_object.cash)
                    print("\n1.back menu")
                    print("2.Logout")
                    choose = int(input())
                    if choose == 1:
                        continue
                    elif choose == 2:
                        break

                elif login_user == 3:
                    print("Balance =", Bank_object.cash)
                    amount = int(input("Enter amount: "))
                    if amount >= 0 and amount <= Bank_object.cash:
                        name = input("Enter person name: ")
                        ph = input("Enter person phone number: ")
                        Bank_object.Tranfer_cash(amount, name, ph)
                        print("\n1.back menu")
                        print("2.Logout")
                        choose = int(input())
                        if choose == 1:
                            continue
                        elif choose == 2:
                            break
                    elif amount < 0:
                        print("Enter please correct value of amount")

                    elif amount > Bank_object.cash:
                        print("Not enough balance")

                elif login_user == 4:
                    print("1.Password change")
                    print("2.Phone Number change")
                    edit_profile = int(input())
                    if edit_profile == 1:
                        new_passwrod = input("Enter new Password: ")
                        Bank_object.password_change(new_passwrod)
                        print("\n1.back menu")
                        print("2.Logout")
                        choose = int(input())
                        if choose == 1:
                            continue
                        elif choose == 2:
                            break
                    elif edit_profile == 2:
                        new_ph = int(input("Enter new Phone Number: "))
                        Bank_object.ph_change(new_ph)
                        print("\n1.back menu")
                        print("2.Logout")
                        choose = int(input())
                        if choose == 1:
                            continue
                        elif choose == 2:
                            break

                elif login_user == 5:
                    break

    if user == 2:
        print("Creating a new  Account")
        name = input("Enter Name: ")
        ph = int(input("Enter Phone Number: "))
        password = input("Enter password: ")
        Bank_object.register(name, ph, password)
