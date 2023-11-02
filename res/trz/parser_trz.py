import struct
import os

def parse_file(dir, name):
    try:
        with open(f'{dir}/{name}', 'rb') as file, open(f'{dir}/{name[:-4]}.txt', 'w') as output:
            num_bloques = struct.unpack('I', file.read(4))[0]

            for bloque in range(num_bloques):
                num_particulas = struct.unpack('q', file.read(8))[0]
                output.write(f'Bloque ({bloque + 1}): {num_particulas} partículas\n')

                for _ in range(num_particulas):
                    id = struct.unpack('q', file.read(8))[0]
                    posx, posy, posz = struct.unpack('ddd', file.read(24))
                    hvx, hvy, hvz = struct.unpack('ddd', file.read(24))
                    velx, vely, vlez = struct.unpack('ddd', file.read(24))
                    density = struct.unpack('d', file.read(8))[0]
                    accx, accy, accz = struct.unpack('ddd', file.read(24))

                    output.write(f'Partícula ID: {id},\nPosición: ({posx}, {posy}, {posz}),\nHv: ({hvx}, {hvy}, {hvz}),\nVelocidad: ({velx}, {vely}, {vlez}),\nDensidad: {density},\nAceleración: ({accx}, {accy}, {accz})\n*********************\n')

                output.write('###############################\n')
        print(f'Procesamiento exitoso: {dir}/{name}')
    except FileNotFoundError:
        print(f'El archivo {dir}/{name} no existe.')
    except struct.error as e:
        print(f'Error al procesar el archivo: {e}')



if __name__ == "__main__":
    large_files = os.listdir("large")
    small_files = os.listdir("small")

    for file in large_files:
        parse_file("large", file)

    for file in large_files:
        parse_file("small", file)
