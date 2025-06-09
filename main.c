#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int completed[MAX_TASKS];
int taskCount = 0;

// 顯示選單
void showMenu() {
    printf("=== 每日待辦事項清單 ===\n");
    printf("1. 新增任務\n");
    printf("2. 顯示任務\n");
    printf("3. 標記任務為完成\n");
    printf("4. 刪除任務\n");
    printf("5. 離開\n");
    printf("請輸入選項：");
}

// 功能 1：新增任務
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("❌ 任務已滿，無法新增。\n");
        return;
    }
    printf("請輸入任務內容：");
    getchar(); // 清除前一次輸入留下的換行符
    fgets(tasks[taskCount], MAX_LENGTH, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0'; // 去除換行符
    completed[taskCount] = 0;
    taskCount++;
    printf("✅ 任務已新增！\n\n");
}

// 功能 2：顯示任務
void showTasks() {
    if (taskCount == 0) {
        printf("目前沒有任務喔！\n\n");
        return;
    }
    printf("目前任務列表：\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i], completed[i] ? "已完成 ✅" : "未完成 ❌");
    }
    printf("\n");
}

// 功能 3：標記為完成
void markCompleted() {
    if (taskCount == 0) {
        printf("目前沒有任務可標記。\n\n");
        return;
    }

    int index;
    printf("請輸入要標記為完成的任務編號：");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("❌ 無效的任務編號。\n\n");
        return;
    }

    if (completed[index - 1]) {
        printf("該任務已經是完成狀態。\n\n");
    } else {
        completed[index - 1] = 1;
        printf("✅ 任務已標記為完成！\n\n");
    }
}

// 功能 4：刪除任務
void deleteTask() {
    if (taskCount == 0) {
        printf("目前沒有任務可刪除。\n\n");
        return;
    }

    int index;
    printf("請輸入要刪除的任務編號：");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("❌ 無效的任務編號。\n\n");
        return;
    }

    // 把後面任務往前移
    for (int i = index - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
        completed[i] = completed[i + 1];
    }
    taskCount--;

    printf("🗑️ 任務已刪除！\n\n");
}

// 主程式
int main() {
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("感謝使用，再見！\n");
                return 0;
            default:
                printf("請輸入 1~5 的數字選項\n\n");
        }
    }
}
