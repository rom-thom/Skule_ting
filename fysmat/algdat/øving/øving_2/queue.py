
class Queue:

    def __init__(self, max_size):
        # Initialiser de underliggende datastrukturene her
        self.max_size = max_size
        self.items = []

    def enqueue(self, value):
        # Skriv kode for Enqueue operasjonen
        if len(self.items) < self.max_size:
            self.items.append(value)

    def dequeue(self):
        # Skriv kode for Dequeue operasjonen
        if not self.is_empty():
            return self.items.pop(0)
        
             


# Sett 'highscore' til True hvis du vil vises på poengtavlen.
# For mer info se 'https://algdat.idi.ntnu.no/ovinger.html#poengtavle'
# Merk: Kjøring for poengtavlen tar betraktelig lengre tid.
highscore = False