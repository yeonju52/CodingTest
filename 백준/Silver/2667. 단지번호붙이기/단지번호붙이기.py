n = int(input())
graph = [] # 초기 맵 리스트
# visited = [[0] * n for _ in range(n)]
result = []

for _ in range(n):
    graph.append(list(map(int, input())))

# 4가지 이동 방향에 대한 리스트
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def dfs(x, y, label):
	# visited[x][y] = label # 방문 처리
	graph[x][y] = 0 # 방문 처리
	result[-1] += 1
	for i in range(4):
		nx = x + dx[i]
		ny = y + dy[i]
		# 상, 하, 좌, 우 중에서 집이 있는 경우
		if nx >= 0 and nx < n and ny >= 0 and ny < n:
			if graph[nx][ny] == 1:
				# if visited[nx][ny] == 0:
					dfs(nx, ny, label)

label = 0
for i in range(n):
	for j in range(n):
		if graph[i][j] == 1:
			# if visited[i][j] == 0:
				label += 1
				result.append(0)
				dfs(i, j, label)

# # 그림 2 확인
# for i in range(n):
# 	for j in range(n):
# 		print(visited[i][j], end=" ")
# 	print()

result.sort()
print(len(result))
for cnt in result:
	print(cnt)