#include <GLFW/glfw3.h>
#include <GL/gl.h>

// Переменные для управления вращением
float rotationAngle = 0.0f;
float rotationSpeed = 0.1f;

void render() {
    // Очистка буфера цвета и глубины
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Сохранение текущей матрицы
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Вращение объекта
    glRotatef(rotationAngle, 1.0f, 0.5f, 0.0f);

    // Отрисовка объекта (куб)
    glBegin(GL_QUADS);
    // Верхняя грань
    glColor3f(1.0f, 0.0f, 0.0f); // Красный
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    // Нижняя грань
    glColor3f(0.0f, 1.0f, 0.0f); // Зеленый
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Боковые грани
    glColor3f(0.0f, 0.0f, 1.0f); // Синий
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glColor3f(1.0f, 1.0f, 0.0f); // Желтый
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    // Передняя и задняя грани
    glColor3f(1.0f, 0.0f, 1.0f); // Фиолетовый
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 1.0f); // Бирюзовый
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();

    // Восстановление предыдущей матрицы
    glPopMatrix();
}

void update() {
    // Увеличение угла вращения
    rotationAngle += rotationSpeed;

    // Ограничение угла вращения от 0 до 360 градусов
    if (rotationAngle >= 360.0f) {
        rotationAngle -= 360.0f;
    }
}

int main() {
    // Инициализация GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, u8"Вращающийся куб", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Установка контекста OpenGL
    glfwMakeContextCurrent(window);

    // Включение буфера глубины
    glEnable(GL_DEPTH_TEST);

    // Основной цикл рендеринга
    while (!glfwWindowShouldClose(window)) {
        // Обновление объекта
        update();

        // Рендеринг объекта
        render();

        // Переключение буферов и обработка событий
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Завершение работы
    glfwTerminate();
    return 0;
}
