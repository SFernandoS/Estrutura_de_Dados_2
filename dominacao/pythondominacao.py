import random
import heapq


class Position:
    def __init__(self, x, y, pontuation=None):
        self.x = x
        self.y = y
        self.pontuation = pontuation

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):
        return self.pontuation > other.pontuation

    def __hash__(self):
        return hash(self.x)

    def __str__(self):
        return f"Position(x={self.x}, y={self.y}, pontuation={self.pontuation})"
        


# Posições já dominadas
dominated_positions: set = set()

# Posições já sondadas
probing_positions: set = set()

# Posições válidas para sondagem
val_pos_probing: set = set()

# Posições válidas para dominar
val_pos_dominate: set = set()

# positions dominated in the previous round
pos_dom_prev: set = set()

# Posições sondadas na rodada anterior
pos_sondagem_prev: set = set()


def get_pos_pontuation(pos):
    return random.randint(-100, 100)


def get_total_points():
    total = 0
    for pos in dominated_positions:
        total += pos.pontuation

    return total

def best_pos_dominate():
    list_val_pos_dominate = list(val_pos_dominate)
    heapq.heapify(list_val_pos_dominate)
    best_pos = heapq.heappop(list_val_pos_dominate)
    val_pos_dominate.remove(best_pos)

    return best_pos

def expand_horizon(pos: Position):
    for dif_x in [-1, 0, 1]:
        for dif_y in [-1, 0, 1]:
            if dif_x == 0 and dif_y == 0:
                continue
            else:
                new_pos = Position(x=pos.x + dif_x, y=pos.y + dif_y)

                if new_pos in dominated_positions:
                    continue

                elif new_pos in probing_positions:
                    continue

                print(f"Nova posição: x={new_pos.x}, y={new_pos.y}")
                val_pos_probing.add(new_pos)


def run_strategy():
    global dominated_positions
    global pos_dom_prev
    global val_pos_dominate
    global pos_sondagem_prev

    dominated_positions = dominated_positions.union(pos_dom_prev)
    val_pos_dominate = val_pos_dominate.union(pos_sondagem_prev)

    # Encontrar os vizinhos das posições que dominei na rodada anterior
    for pos in pos_dom_prev:
        expand_horizon(pos)

    pos_sondagem_prev = set()
    pos_dom_prev = set()

    for mov in range(len(dominated_positions)):

        if len(val_pos_dominate) != 0:
            # pos: Position = val_pos_dominate.pop()
            pos = best_pos_dominate()
            print("dominei", pos)
            pos_dom_prev.add(pos)

        elif len(val_pos_probing) != 0:
            pos: Position = val_pos_probing.pop()
            pos.pontuation = get_pos_pontuation(pos)
            pos_sondagem_prev.add(pos)
            print("sondei", pos)

        else:
            raise Exception("Impossível!")


def run_game(rounds=2, x=0, y=0, pontuation=10):

    global dominated_positions
    dominated_positions = set()
    
    global probing_positions
    probing_positions = set()

    global val_pos_probing
    val_pos_probing = set()

    global val_pos_dominate
    val_pos_dominate = set()

    global pos_dom_prev
    pos_dom_prev = set()

    global pos_sondagem_prev
    pos_sondagem_prev = set()

    pos: Position = Position(x=x, y=y, pontuation=pontuation)
    pos_dom_prev.add(pos)

    for i in range(rounds):
        print("Inicio da rodada", i+1)
        run_strategy()

    points = get_total_points()
    print('Pontuação total:', points)
    return points


if __name__ == '__main__':
    simulation_count = 1000
    sum_points = 0

    for i in range(simulation_count):
        sum_points += run_game()

    media = sum_points / simulation_count
    print("Media da estrategia: ", media)
