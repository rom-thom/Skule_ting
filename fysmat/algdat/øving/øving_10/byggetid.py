




total_time_to_build = {}



def building_time(tasks):
    if len(tasks) == 0:
        return 0

    max_total_time = 0
    for t in tasks:
        if t not in total_time_to_build:
            total_time_to_build[t] = building_time(t.depends_on) + t.time

        if max_total_time < total_time_to_build[t]:
            max_total_time = total_time_to_build[t]
    return max_total_time

    

