# Weather Control System

Sistema de control meteorológico en C++ con interfaz de usuario por consola.

## Estructura del Proyecto

```
finalalgoII/
├── Forecast.h              # Declaración de la clase Forecast
├── Forecast.cpp            # Implementación de la clase Forecast
├── WeatherLog.h            # Declaración de la clase WeatherLog
├── WeatherLog.cpp          # Implementación de la clase WeatherLog
├── WeatherControl.h        # Declaración de la clase WeatherControl
├── WeatherControl.cpp      # Implementación de la clase WeatherControl
├── WeatherControlUI.h      # Declaración de la clase WeatherControlUI
├── WeatherControlUI.cpp    # Implementación de la clase WeatherControlUI
├── main_new.cpp            # Punto de entrada del programa
├── compile.bat             # Script de compilación para Windows
├── compile.sh              # Script de compilación para Linux
└── README.md               # Este archivo
```

## Clases del Sistema

### Forecast
- Gestiona los valores de temperatura y humedad
- Métodos para aumentar/disminuir temperatura y humedad
- Lectura de valores actuales

### WeatherLog
- Registra datos meteorológicos con fecha y hora
- Almacena temperatura, humedad y timestamp
- Métodos para modificar y consultar datos

### WeatherControl
- Controlador principal del sistema
- Gestiona la lista de logs meteorológicos
- Conecta Forecast con WeatherLog
- Funciones de búsqueda y actualización

### WeatherControlUI
- Interfaz de usuario por consola
- Menú interactivo para gestionar el sistema
- Funciones de visualización y entrada de datos

## Compilación

### Windows
```bash
# Ejecutar el archivo .bat
compile.bat
```

### Linux/Mac
```bash
# Dar permisos de ejecución al script
chmod +x compile.sh

# Ejecutar el script
./compile.sh
```

### Compilación Manual
```bash
# Compilar archivos objeto
g++ -c Forecast.cpp -o Forecast.o
g++ -c WeatherLog.cpp -o WeatherLog.o
g++ -c WeatherControl.cpp -o WeatherControl.o
g++ -c WeatherControlUI.cpp -o WeatherControlUI.o
g++ -c main_new.cpp -o main_new.o

# Enlazar y crear ejecutable
g++ Forecast.o WeatherLog.o WeatherControl.o WeatherControlUI.o main_new.o -o weather_app
```

## Uso del Programa

1. Ejecutar el programa compilado
2. Navegar por el menú usando números:
   - 1: Mostrar clima actual
   - 2: Mostrar logs
   - 3: Aumentar temperatura
   - 4: Disminuir temperatura
   - 5: Aumentar humedad
   - 6: Disminuir humedad
   - 7: Mostrar menú
   - 8: Salir

## Requisitos

- Compilador C++ (g++, clang++, etc.)
- Soporte para C++11 o superior
- Sistema operativo Windows o Linux/Mac

## Características

- Separación de responsabilidades en clases
- Interfaz de usuario intuitiva
- Registro automático de cambios
- Visualización de historial de datos
- Compilación multiplataforma 