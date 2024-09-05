import pandas as pd

# Datos de las actividades y sus ponderaciones
data = {
    "Actividad": [
        "Entrega del escrito de la Sit.",
        "Quiz 1 - Canvas",
        "Tarea 2 G104-2024",
        "Actividad 4 EDNH con CC",
        "Actividad 1 Ecuaciones",
        "E2 Exposición oral",
        "Quiz 2 - MA1033-G103",
        "Tarea 3 G104-EDNlineales",
        "Tarea 4 Métodos de Integr",
        "Actividad 2 Ecuaciones Exactas",
        "E1 Examen argumentativo",
        "Entrega de la Fase 1 - Situación",
        "Tarea 4 G104-EDNH de org",
        "Tarea 1 G104-2024",
        "Actividad 3 Ecuaciones Dif."
    ],
    "Ponderación (%)": [
        6, 7.5, 2, 2.5, 2.5, 5, 7.5, 2, 2, 2.5, 50, 4, 2, 2, 2.5
    ],
    "Calificación Obtenida": [
        80,  #CALIFICADA   
        0,   #CALIFICADA
        100, #CALIFICADA
        95,  #ACTIVIDAD 
        95,  #CALIFICADA
        70,  #VIDEO ELUMEN
        100, #CALIFICADA
        100, #CALIFICADA
        100, #CALIFICADA
        90,  #CALIFICADA
        100,  #EXAMEN 
        70,  #CALIFICADA
        100, #CALIFICADA
        87,  #CALIFICADA
        98   #CALIFICADA
    ]
}

# Crear DataFrame
df = pd.DataFrame(data)

# Función para calcular la contribución de cada actividad
def calcular_contribucion(row):
    if row["Calificación Obtenida"] is not None:
        return (row["Ponderación (%)"] / 100) * row["Calificación Obtenida"]
    else:
        return 0  # Si no hay calificación, su contribución es 0

# Aplicar la función al DataFrame
df["Contribución a la Calificación Final"] = df.apply(calcular_contribucion, axis=1)

# Calcular la calificación final sumando las contribuciones
calificacion_final = df["Contribución a la Calificación Final"].sum()

# Mostrar la calificación final
print(f"Tu calificación final ponderada es: {calificacion_final:.2f} sobre 100")