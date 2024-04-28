package com.lab4;


import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.JsonNode;

public class Utils {
    public class JsonConverter {

        private static final ObjectMapper objectMapper = new ObjectMapper();

        public static <T> T fromJsonString(String json, Class<T> valueType) throws JsonProcessingException {
            return objectMapper.readValue(json, valueType);
        }

        public static String toJsonString(Object value) throws JsonProcessingException {
            return objectMapper.writeValueAsString(value);
        }

        // 如果你需要将JSON字符串转换为JsonNode，可以添加以下方法
        public static JsonNode toJsonNode(String json) throws JsonProcessingException {
            return objectMapper.readTree(json);
        }
    }

    public static int random(int min, int max) {
        return (int) (Math.random() * (max - min + 1) + min);
    }
}