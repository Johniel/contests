package main

import (
	"bufio"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

// `path` represents `CONTESTSITE/CONTEST/PROBLEM/README.md`
// e.g.) codeforces/431div2/A/README.md

// output: docs/codeforces/431div2/A.md

func gen(path string) error {
	var err error

	ss := strings.Split(path, string(filepath.Separator))
	if len(ss) != 4 {
		log.Println("[SKIP]: " + path)
		return nil
	}

	log.Println("[GENERATE]: " + path)

	codePath := strings.Replace(path, "README.md", "main.cpp", -1)
	outputPath := strings.Replace("docs"+string(filepath.Separator)+path, "/README", "", -1)
	outputDir, _ := filepath.Split(outputPath)

	err = exec.Command("mkdir", "-p", outputDir).Run()
	if err != nil {
		return err
	}

	err = exec.Command("cp", path, outputPath).Run()
	if err != nil {
		return err
	}

	err = exec.Command("bash", "-c", "echo '\n## Code' >> "+outputPath).Run()
	if err != nil {
		return err
	}

	err = exec.Command("bash", "-c", "echo '```cpp' >> "+outputPath).Run()
	if err != nil {
		return err
	}

	err = exec.Command("bash", "-c", "cat "+codePath+" >> "+outputPath).Run()
	if err != nil {
		return err
	}

	err = exec.Command("bash", "-c", "echo '```' >> "+outputPath).Run()
	if err != nil {
		return err
	}

	return nil
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		err := gen(line)
		if err != nil {
			log.Println(err.Error())
			return
		}
	}
	return
}
